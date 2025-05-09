import { View, Text, ScrollView, StyleSheet, TouchableOpacity, Image} from "react-native";
import React, { useEffect, useState} from "react";
import Header from "./Header";
import Request from "./Request";
import getToken from "./GetToken";
import { API_KEY } from "./config";
import storeToken from "./StoreToken";
import OtherProfile from "./OtherProfile";
import { CommonActions } from "@react-navigation/native";

const styles = StyleSheet.create({
  back: {
    backgroundColor: '#e5e5e5',
  },

  doctorsContainer: {
    marginTop: 15,
    paddingHorizontal: 15,
    paddingVertical: 15,
  },

  doctorCard: {
    flex: 1,
    flexDirection: 'row',
    backgroundColor: 'white',
    elevation: 5,
    padding: 10,
    paddingHorizontal: 15,
    paddingVertical: 15,
    marginBottom: 20,
    borderRadius: 15,
  },

  employeeImg: {
    width: 60,
    height: 60,
    borderRadius: 60/2,
    marginRight: 25,
  },

  employeeInfo: {
    flexDirection: 'column'
  },

  employeeName: {
    fontWeight: 'bold',
    fontSize: 16,
    marginBottom: 10,
  },

  employeeSpe: {
    backgroundColor: '#20e9d0',
    padding: 5,
    paddingHorizontal: 15,
    fontSize: 14,
    color: 'white',
  },

  employeeSpeContainer: {
    borderRadius: 15,
    overflow: 'hidden',
  },

});

const Trombi = ({ navigation }) => {
  const [useData, setData] = useState([]);
  const [useToken, setToken] = useState();

  const SeeProfile = (key) => {
    storeToken(key.toString(), "id");
    const id = key.toString();
    navigation.dispatch (
      CommonActions.navigate({
          name: 'OtherProfile',
          params: {
            id: id,
          },
      }),

    );
  };

  useEffect(() => {
    const getTrombi = async () => {
      try {
        const token = await getToken("token");
        setToken(token);
        ResponseJson = await Request("https://masurao.fr/api/employees", "application/json",  token);
        const Data = JSON.parse(JSON.stringify(ResponseJson));
        setData(Data);
      } catch (error) {
        console.error(error);
      }
    };
    getTrombi();
  }, []);
    return (
    <View>
      <Header />
      <ScrollView style={styles.back}>
        <View style={styles.doctorsContainer}>
          { useData.map((employee, index)=>{
              return (
                <TouchableOpacity key={employee.id} style={styles.doctorCard} onPress={() => {SeeProfile(employee.id)}}>
                  <Image
                    source={{uri: `https://masurao.fr/api/employees/${employee.id}/image`, 
                    headers:{
                      'X-Group-Authorization' : API_KEY,
                      'Authorization' : `Bearer ${useToken}`
                    } }}
                    onError={e => console.log(e)}
                    style={styles.employeeImg}
                  />
                  <View style={styles.employeeInfo}>
                    <Text style={styles.employeeName}>{employee.name + " " + employee.surname}</Text>
                    <View style={styles.employeeSpeContainer}>
                      <Text style={styles.employeeSpe}>{employee.email}</Text>
                    </View>
                  </View>
                </TouchableOpacity>
              );
          })}
        </View>
      </ScrollView>
    </View>
    );
};

export default Trombi;