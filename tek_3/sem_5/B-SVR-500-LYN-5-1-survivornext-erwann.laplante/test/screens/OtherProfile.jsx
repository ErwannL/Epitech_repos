import { View, Text, Image, StyleSheet, TouchableOpacity, ScrollView} from "react-native";
import React, {useEffect, useState} from "react";
import { useNavigation } from '@react-navigation/native';
import axios from 'axios';
import { FontAwesome } from '@expo/vector-icons';
import QRCode from 'react-native-qrcode-svg';
import { API_KEY } from "./config";
import getToken from "./GetToken";

const styles = StyleSheet.create({

    containerQr: {
        justifyContent: 'center',
        alignSelf: "center",
        alignItems: 'center',
        height: 280,
        width: 280,
        borderRadius: 20,
        backgroundColor: 'white',
        marginTop: 25,
    },

    text: {
        paddingBottom: 20,
        fontWeight: 'bold',
        fontSize: 14,
    },

    container: {
        backgroundColor: 'white',
        padding: 20,
        marginTop: 40,
        marginLeft: 20,
        height: '30%',
        width: '90%',
        borderRadius: 30,
    },

    header: {
        width: '100%',
        height: '30%',
        backgroundColor: '#20E9D0',
    },

    styleImg: {
        width: 140,
        height: 140,
        alignSelf: "center",
        marginTop: '20%',
        borderRadius: 140/2,
    },

    styleTxt: {
        alignSelf: "center",
        paddingTop: 10,
    },

    Logout: {
        alignSelf: 'flex-end',
        position: 'absolute',
        top: '20%',
        right: '5%',
    },

    goBack: {
        alignSelf: 'flex-end',
        position: 'absolute',
        top: '20%',
        left: '5%',
    },
});

const OtherProfile = () => {
    const navigation = useNavigation();
    const [Email, setEmail] = useState('');
    const [Id, setId] = useState('');
    const [Name, setName] = useState('');
    const [Surname, setSurname] = useState('');
    const [Work, setWork] = useState('');
    const [Birth, setBirth] = useState('');
    const [Gender, setGender] = useState('');
    const qrCodeContent = `mailto:${Email}`;
    const [useToken, setToken] = useState();

    const handleLogout = () => {
        navigation.navigate('Login');
    }

    const handleBack = () => {
        navigation.goBack();
    }


    const handleProfile = async () => {
        try {
            const token = await getToken("token");
            setToken(token);
            var id = await getToken("id");
            id = parseInt(id);
        const result = await axios.get(
            `https://masurao.fr/api/employees/${id}`,
            {headers: {
                'X-Group-Authorization': API_KEY,
                'Authorization': `Bearer ${token}`}}
        );
            setEmail(result.data.email);
            setId(result.data.id);
            setName(result.data.name);
            setGender(result.data.gender);
            setSurname(result.data.surname);
            setWork(result.data.work);
            setBirth(result.data.birth_date);
        } catch (error) {
            console.log(error);
        }
    };

    useEffect(() => {
        handleProfile();
    }, []);

    return (
        <ScrollView>
            <View style={styles.header}>
            <TouchableOpacity style={styles.Logout} onPress={handleLogout}>
                <FontAwesome name="sign-out" size={30} color="grey" />
            </TouchableOpacity>
            <TouchableOpacity style={styles.goBack} onPress={() => {handleBack()}}>
                <FontAwesome name="arrow-left" size={30} color="grey" />
            </TouchableOpacity>
            <Image source={{uri: `https://masurao.fr/api/employees/${Id}/image`, 
                    headers:{
                      'X-Group-Authorization' : API_KEY,
                      'Authorization' : `Bearer ${useToken}`
                    } }} style={styles.styleImg}/>
            </View>
            <View style={styles.container}>
                <Text style={styles.text}>Prénom: {Name}</Text>
                <Text style={styles.text}>Nom: {Surname} </Text>
                <Text style={styles.text}>Gender: {Gender} </Text>
                <Text style={styles.text}>Email: {Email}</Text>
                <Text style={styles.text}>Poste: {Work}</Text>
                <Text style={styles.text}>Date de naissance: {Birth}</Text>
            </View>
            <View style={styles.containerQr}>
                <QRCode
                    value={qrCodeContent}
                    color="#20E9D0"
                    size={250}
                    alignSelf
                />
            </View>
        </ScrollView>
    );
};

export default OtherProfile;