#!/bin/bash

# URL de votre serveur
SERVER_URL="http://localhost:8080"

# Initialise la variable de statut à 0 (pas d'erreur)
STATUS=0

# Fonction pour tester la route about
test_about_route() {
  response=$(curl -s -w "%{http_code}" -X GET "$SERVER_URL/about.json")
  response_code="${response: -3}"
  response_data="${response::-3}"

  if [ "$response_code" = "200" ]; then
    echo "Route about a réussi."
  else
    echo "Route about a échoué. Réponse : $response_data"
    STATUS=-42
  fi
}

# Fonction pour tester une route GET
test_get_route() {
  local route="$1"
  local token="$2"
  local expected_response="$3"
  local data="$4"

  if [ "$data" ]; then
    response=$(curl -s -w "%{http_code}" -X GET -H "Authorization: $token" -d "$data" "$SERVER_URL/$route")
  else
    response=$(curl -s -w "%{http_code}" -X GET -H "Authorization: $token" "$SERVER_URL/$route")
  fi

  response_code="${response: -3}"
  response_data="${response::-3}"

  if [ "$expected_response" ]; then
    if [ "$response_code" = "200" ] && [ "$response_data" = "$expected_response" ]; then
      echo "Route GET $route a réussi."
    else
      echo "Route GET $route a échoué. Réponse : $response_data"
      STATUS=-42
    fi
  fi
}

# Fonction pour tester une route POST
test_post_route() {
  local route="$1"
  local data="$2"
  local expected_response="$3"

  response=$(curl -s -w "%{http_code}" -X POST -H "Content-Type: application/json" -d "$data" "$SERVER_URL/$route")
  response_code="${response: -3}"
  response_data="${response::-3}"

  if [ "$expected_response" ]; then
    if [ "$response_code" = "200" ] && [ "$response_data" = "$expected_response" ]; then
      echo "Route POST $route a réussi."
    else
      echo "Route POST $route a échoué. Réponse : $response_data"
      STATUS=-42
    fi
  else
    if [ "$response_code" = "200" ]; then
      echo "Route POST $route a réussi."
      echo "$response_data" > token.json
    else
      echo "Route POST $route a échoué. Statut HTTP : $response_code"
      STATUS=-42
    fi
  fi
}

# Fonction pour tester une route POST vérifiée
test_post_verified_route() {
  local route="$1"
  local data="$2"
  local token="$3"
  local expected_response="$4"

  response=$(curl -s -w "%{http_code}" -X POST -H "Content-Type: application/json" -H "Authorization: $token" -d "$data" "$SERVER_URL/$route")
  response_code="${response: -3}"
  response_data="${response::-3}"

  if [ "$expected_response" ]; then
    if [ "$response_code" = "200" ] && [ "$response_data" = "$expected_response" ]; then
      echo "Route POST $route a réussi."
    else
      echo "Route POST $route a échoué. Réponse : $response_data"
      STATUS=-42
    fi
  fi
}

# Tester les routes
test_about_route
test_post_route "register" '{"username": "user", "password": "password"}' '{"message":"User registered"}'
test_post_route "login" '{"username": "user", "password": "password"}'
token=$(grep -o '"token":"[^"]*' token.json | sed 's/"token":"//')
test_post_verified_route "addScenario" '{"scenario_name": "NomDuScenario", "scenario_description": "DescriptionDuScenario"}' "$token" '{"success":true,"message":"scenario added","scenario":{"id":1,"user_id":1,"scenario_name":"NomDuScenario","scenario_description":"DescriptionDuScenario"}}'
test_get_route "getScenarios" "$token" '{"success":true,"message":"scenario fetched","result":{"command":"SELECT","rowCount":1,"oid":null,"rows":[{"id":1,"user_id":1,"scenario_name":"NomDuScenario","scenario_description":"DescriptionDuScenario"}],"fields":[{"name":"id","tableID":16398,"columnID":1,"dataTypeID":23,"dataTypeSize":4,"dataTypeModifier":-1,"format":"text"},{"name":"user_id","tableID":16398,"columnID":2,"dataTypeID":23,"dataTypeSize":4,"dataTypeModifier":-1,"format":"text"},{"name":"scenario_name","tableID":16398,"columnID":3,"dataTypeID":1043,"dataTypeSize":-1,"dataTypeModifier":259,"format":"text"},{"name":"scenario_description","tableID":16398,"columnID":4,"dataTypeID":25,"dataTypeSize":-1,"dataTypeModifier":-1,"format":"text"}],"_parsers":[null,null,null,null],"_types":{"_types":{"arrayParser":{},"builtins":{"BOOL":16,"BYTEA":17,"CHAR":18,"INT8":20,"INT2":21,"INT4":23,"REGPROC":24,"TEXT":25,"OID":26,"TID":27,"XID":28,"CID":29,"JSON":114,"XML":142,"PG_NODE_TREE":194,"SMGR":210,"PATH":602,"POLYGON":604,"CIDR":650,"FLOAT4":700,"FLOAT8":701,"ABSTIME":702,"RELTIME":703,"TINTERVAL":704,"CIRCLE":718,"MACADDR8":774,"MONEY":790,"MACADDR":829,"INET":869,"ACLITEM":1033,"BPCHAR":1042,"VARCHAR":1043,"DATE":1082,"TIME":1083,"TIMESTAMP":1114,"TIMESTAMPTZ":1184,"INTERVAL":1186,"TIMETZ":1266,"BIT":1560,"VARBIT":1562,"NUMERIC":1700,"REFCURSOR":1790,"REGPROCEDURE":2202,"REGOPER":2203,"REGOPERATOR":2204,"REGCLASS":2205,"REGTYPE":2206,"UUID":2950,"TXID_SNAPSHOT":2970,"PG_LSN":3220,"PG_NDISTINCT":3361,"PG_DEPENDENCIES":3402,"TSVECTOR":3614,"TSQUERY":3615,"GTSVECTOR":3642,"REGCONFIG":3734,"REGDICTIONARY":3769,"JSONB":3802,"REGNAMESPACE":4089,"REGROLE":4096}},"text":{},"binary":{}},"RowCtor":null,"rowAsArray":false,"_prebuiltEmptyResultObject":{"id":null,"user_id":null,"scenario_name":null,"scenario_description":null}}}'
test_get_route "getScenario" "$token" '{"success":true,"message":"scenario fetched","result":{"command":"SELECT","rowCount":0,"oid":null,"rows":[],"fields":[{"name":"id","tableID":16398,"columnID":1,"dataTypeID":23,"dataTypeSize":4,"dataTypeModifier":-1,"format":"text"},{"name":"user_id","tableID":16398,"columnID":2,"dataTypeID":23,"dataTypeSize":4,"dataTypeModifier":-1,"format":"text"},{"name":"scenario_name","tableID":16398,"columnID":3,"dataTypeID":1043,"dataTypeSize":-1,"dataTypeModifier":259,"format":"text"},{"name":"scenario_description","tableID":16398,"columnID":4,"dataTypeID":25,"dataTypeSize":-1,"dataTypeModifier":-1,"format":"text"}],"_parsers":[null,null,null,null],"_types":{"_types":{"arrayParser":{},"builtins":{"BOOL":16,"BYTEA":17,"CHAR":18,"INT8":20,"INT2":21,"INT4":23,"REGPROC":24,"TEXT":25,"OID":26,"TID":27,"XID":28,"CID":29,"JSON":114,"XML":142,"PG_NODE_TREE":194,"SMGR":210,"PATH":602,"POLYGON":604,"CIDR":650,"FLOAT4":700,"FLOAT8":701,"ABSTIME":702,"RELTIME":703,"TINTERVAL":704,"CIRCLE":718,"MACADDR8":774,"MONEY":790,"MACADDR":829,"INET":869,"ACLITEM":1033,"BPCHAR":1042,"VARCHAR":1043,"DATE":1082,"TIME":1083,"TIMESTAMP":1114,"TIMESTAMPTZ":1184,"INTERVAL":1186,"TIMETZ":1266,"BIT":1560,"VARBIT":1562,"NUMERIC":1700,"REFCURSOR":1790,"REGPROCEDURE":2202,"REGOPER":2203,"REGOPERATOR":2204,"REGCLASS":2205,"REGTYPE":2206,"UUID":2950,"TXID_SNAPSHOT":2970,"PG_LSN":3220,"PG_NDISTINCT":3361,"PG_DEPENDENCIES":3402,"TSVECTOR":3614,"TSQUERY":3615,"GTSVECTOR":3642,"REGCONFIG":3734,"REGDICTIONARY":3769,"JSONB":3802,"REGNAMESPACE":4089,"REGROLE":4096}},"text":{},"binary":{}},"RowCtor":null,"rowAsArray":false,"_prebuiltEmptyResultObject":{"id":null,"user_id":null,"scenario_name":null,"scenario_description":null}}}' "{'id': "1"}"
test_post_verified_route "addScenario" '{"scenario_name": "Scenario2", "scenario_description": "DescriptionDuScenario"}' "$token" '{"success":true,"message":"scenario added","scenario":{"id":2,"user_id":1,"scenario_name":"Scenario2","scenario_description":"DescriptionDuScenario"}}'
test_get_route "getScenarios" "$token" '{"success":true,"message":"scenario fetched","result":{"command":"SELECT","rowCount":2,"oid":null,"rows":[{"id":1,"user_id":1,"scenario_name":"NomDuScenario","scenario_description":"DescriptionDuScenario"},{"id":2,"user_id":1,"scenario_name":"Scenario2","scenario_description":"DescriptionDuScenario"}],"fields":[{"name":"id","tableID":16398,"columnID":1,"dataTypeID":23,"dataTypeSize":4,"dataTypeModifier":-1,"format":"text"},{"name":"user_id","tableID":16398,"columnID":2,"dataTypeID":23,"dataTypeSize":4,"dataTypeModifier":-1,"format":"text"},{"name":"scenario_name","tableID":16398,"columnID":3,"dataTypeID":1043,"dataTypeSize":-1,"dataTypeModifier":259,"format":"text"},{"name":"scenario_description","tableID":16398,"columnID":4,"dataTypeID":25,"dataTypeSize":-1,"dataTypeModifier":-1,"format":"text"}],"_parsers":[null,null,null,null],"_types":{"_types":{"arrayParser":{},"builtins":{"BOOL":16,"BYTEA":17,"CHAR":18,"INT8":20,"INT2":21,"INT4":23,"REGPROC":24,"TEXT":25,"OID":26,"TID":27,"XID":28,"CID":29,"JSON":114,"XML":142,"PG_NODE_TREE":194,"SMGR":210,"PATH":602,"POLYGON":604,"CIDR":650,"FLOAT4":700,"FLOAT8":701,"ABSTIME":702,"RELTIME":703,"TINTERVAL":704,"CIRCLE":718,"MACADDR8":774,"MONEY":790,"MACADDR":829,"INET":869,"ACLITEM":1033,"BPCHAR":1042,"VARCHAR":1043,"DATE":1082,"TIME":1083,"TIMESTAMP":1114,"TIMESTAMPTZ":1184,"INTERVAL":1186,"TIMETZ":1266,"BIT":1560,"VARBIT":1562,"NUMERIC":1700,"REFCURSOR":1790,"REGPROCEDURE":2202,"REGOPER":2203,"REGOPERATOR":2204,"REGCLASS":2205,"REGTYPE":2206,"UUID":2950,"TXID_SNAPSHOT":2970,"PG_LSN":3220,"PG_NDISTINCT":3361,"PG_DEPENDENCIES":3402,"TSVECTOR":3614,"TSQUERY":3615,"GTSVECTOR":3642,"REGCONFIG":3734,"REGDICTIONARY":3769,"JSONB":3802,"REGNAMESPACE":4089,"REGROLE":4096}},"text":{},"binary":{}},"RowCtor":null,"rowAsArray":false,"_prebuiltEmptyResultObject":{"id":null,"user_id":null,"scenario_name":null,"scenario_description":null}}}'
test_post_verified_route "addComponent" '{"scenario_id": "1", "component_name": "action", "component_type": "SendMsgDiscord", "link_to": "test1"}' "$token" '{"message":"Component added successfully"}'
test_post_verified_route "addComponent" '{"scenario_id": "1", "component_name": "reaction", "component_type": "GetEmailGmail", "link_to": "test2"}' "$token" '{"message":"Component added successfully"}'
test_post_verified_route "getComponents" '{"id": "1"}' "$token" '{"success":true,"message":"components fetched","result":{"command":"SELECT","rowCount":2,"oid":null,"rows":[{"id":1,"scenario_id":1,"component_name":"action","component_type":"SendMsgDiscord","link_to":"test1"},{"id":2,"scenario_id":1,"component_name":"reaction","component_type":"GetEmailGmail","link_to":"test2"}],"fields":[{"name":"id","tableID":16412,"columnID":1,"dataTypeID":23,"dataTypeSize":4,"dataTypeModifier":-1,"format":"text"},{"name":"scenario_id","tableID":16412,"columnID":2,"dataTypeID":23,"dataTypeSize":4,"dataTypeModifier":-1,"format":"text"},{"name":"component_name","tableID":16412,"columnID":3,"dataTypeID":1043,"dataTypeSize":-1,"dataTypeModifier":259,"format":"text"},{"name":"component_type","tableID":16412,"columnID":4,"dataTypeID":1043,"dataTypeSize":-1,"dataTypeModifier":259,"format":"text"},{"name":"link_to","tableID":16412,"columnID":5,"dataTypeID":1043,"dataTypeSize":-1,"dataTypeModifier":259,"format":"text"}],"_parsers":[null,null,null,null,null],"_types":{"_types":{"arrayParser":{},"builtins":{"BOOL":16,"BYTEA":17,"CHAR":18,"INT8":20,"INT2":21,"INT4":23,"REGPROC":24,"TEXT":25,"OID":26,"TID":27,"XID":28,"CID":29,"JSON":114,"XML":142,"PG_NODE_TREE":194,"SMGR":210,"PATH":602,"POLYGON":604,"CIDR":650,"FLOAT4":700,"FLOAT8":701,"ABSTIME":702,"RELTIME":703,"TINTERVAL":704,"CIRCLE":718,"MACADDR8":774,"MONEY":790,"MACADDR":829,"INET":869,"ACLITEM":1033,"BPCHAR":1042,"VARCHAR":1043,"DATE":1082,"TIME":1083,"TIMESTAMP":1114,"TIMESTAMPTZ":1184,"INTERVAL":1186,"TIMETZ":1266,"BIT":1560,"VARBIT":1562,"NUMERIC":1700,"REFCURSOR":1790,"REGPROCEDURE":2202,"REGOPER":2203,"REGOPERATOR":2204,"REGCLASS":2205,"REGTYPE":2206,"UUID":2950,"TXID_SNAPSHOT":2970,"PG_LSN":3220,"PG_NDISTINCT":3361,"PG_DEPENDENCIES":3402,"TSVECTOR":3614,"TSQUERY":3615,"GTSVECTOR":3642,"REGCONFIG":3734,"REGDICTIONARY":3769,"JSONB":3802,"REGNAMESPACE":4089,"REGROLE":4096}},"text":{},"binary":{}},"RowCtor":null,"rowAsArray":false,"_prebuiltEmptyResultObject":{"id":null,"scenario_id":null,"component_name":null,"component_type":null,"link_to":null}}}'
test_get_route "getUserId" "$token" '{"userId":1}'

# Supprimer le fichier temporaire à la fin du script
trap 'rm -f token.json' EXIT

# Renvoie la valeur de la variable de statut à la fin du script
exit $STATUS
