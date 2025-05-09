import { View, Text, Image, StyleSheet, TouchableOpacity, handle} from "react-native";
import { FontAwesome } from '@expo/vector-icons';
import { useNavigation } from '@react-navigation/native';
import React, {useEffect, useState} from "react";
import axios from "axios";
import { API_KEY } from "./config";
import getToken from "./GetToken";

const styles = StyleSheet.create({
    header: {
        width: '100%',
        height: 250,
        backgroundColor: '#20E9D0',
    },

    styleImg: {
        width: 80,
        height: 80,
        alignSelf: "center",
        marginTop: '25%',
        borderRadius: 80/2,
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
});

const Header = () => {
    const [name, setname] = useState('');
    const [id, setid] = useState('');
    const [surname, setsurname] = useState('');
    const [useToken, setToken] = useState();

    const navigation = useNavigation();
    const handleLogout = () => {
        navigation.navigate('Login');
    };
    useEffect(() => {
        const handleHeader = async () => {
            try {
                const token = await getToken("token");
                setToken(token);
                const Info = await axios.get(
                    `https://masurao.fr/api/employees/me`,
                    {headers: {
                        'X-Group-Authorization': API_KEY,
                        'Authorization': `Bearer ${token}`}}
                );
                setid(Info.data.id)
                setname(Info.data.name)
                setsurname(Info.data.surname)
            } catch (error) {
                console.error(error);
            }
            };

        handleHeader();
    }, []);

    return (
        <View style={styles.header}>
            <TouchableOpacity style={styles.Logout} onPress={handleLogout}>
                <FontAwesome name="sign-out" size={30} color="grey" />
            </TouchableOpacity>
            <Image source={{uri: `https://masurao.fr/api/employees/${id}/image`, 
                    headers:{
                      'X-Group-Authorization' : API_KEY,
                      'Authorization' : `Bearer ${useToken}`
                    } }} style={styles.styleImg}/>
            <Text style={styles.styleTxt} >Welcome {name} {surname} !</Text>
        </View>
    );
};

export default Header;