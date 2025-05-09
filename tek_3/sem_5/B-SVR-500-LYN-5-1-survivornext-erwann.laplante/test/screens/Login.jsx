import React, { useState, useEffect } from 'react';
import { Alert, Image, Text, TextInput, View, StyleSheet, TouchableOpacity, KeyboardAvoidingView, Platform, Keyboard, ScrollView } from 'react-native';
import axios from 'axios';
import { useAllInfos } from './Context';
import storeToken from './StoreToken';
import { API_KEY } from './config';
import API from './API';

const EMAIL_REGEX =
  /(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9]))\.){3}(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\])/;

const Login = ({ navigation }) => {
  const [email, setemail] = useState('');
  const [password, setpassword] = useState('');
  const good = EMAIL_REGEX.test(email);
  
  const handleLogin = async () => {
    try {
      const token = await API(email, password);
      storeToken(token.access_token, "token");
      navigation.navigate('MyTabs');
    } catch (error) {
      console.log("error: " + error);
    }
  };

  const handleForgot = () => {
    Alert.alert("Contact your manager", "Only your manager has the right to manage logins")
  }

  useEffect(() => {
    const keyboardDidHideListener = Keyboard.addListener(
      'keyboardDidHide',
      () => {
        Keyboard.dismiss();
      }
    );
    return () => {
      keyboardDidHideListener.remove();
    };
  }, []);

  return (
    <KeyboardAvoidingView
      style={styles.back}
      behavior={Platform.OS === 'ios' ? 'padding' : 'height'}
      keyboardVerticalOffset={50}
    >
      <ScrollView contentContainerStyle={styles.scrollContainer}>
        <View style={styles.fill}>
          <Text style={styles.welcome}>Welcome Back !</Text>
          <Image source={require('../assets/login.png')} style={{ width: 230, height: 230, alignSelf: "center" }} />
        </View>
        <View style={styles.container}>
          <View style={styles.buttonSpace}>
            <TextInput
              style={[styles.textInput]}
              placeholder="Enter your email"
              value={email}
              onChangeText={setemail}
            />
            {!good && email !== '' && (
              <View style={styles.good}>
                <Text style={styles.good}>Wrong email !</Text>
              </View>
            )}
            <TextInput
              style={[styles.textInput]}
              secureTextEntry={true}
              placeholder="Enter your password"
              value={password}
              onChangeText={setpassword}
            />
          </View>
          <View>
            <TouchableOpacity style={styles.buttonTextt}>
              <Text style={styles.buttonTextt} onPress={handleForgot}>Forgot password ?</Text>
            </TouchableOpacity>
          </View>
          <View style={styles.buttonContainer}>
            <TouchableOpacity onPress={handleLogin} style={styles.buttonText}>
              <Text style={styles.buttonText}>LOGIN</Text>
            </TouchableOpacity>
          </View>
        </View>
      </ScrollView>
    </KeyboardAvoidingView>
  );
};

const styles = StyleSheet.create({
  container: {
    alignItems: 'center',
    paddingBottom: 50,
    justifyContent: 'space-between',
    flex: 1,
    paddingTop: 70,
    gap: 20,
  },
  scrollContainer: {
    flexGrow: 1,
    justifyContent: 'center',
  },
  textInput: {
    height: 60,
    width: 340,
    borderColor: 'gray',
    borderWidth: 1,
    borderRadius: 30,
    paddingHorizontal: 10,
    backgroundColor: 'white',
  },
  buttonSpace: {
    gap: 20,
  },
  buttonContainer: {
    height: '20%',
    width: '90%',
    backgroundColor: '#20E9D0',
    paddingVertical: 10,
    paddingHorizontal: 20,
    borderRadius: 10,
  },
  buttonText: {
    color: 'white',
    fontSize: 18,
    alignItems: 'center',
    paddingTop: 5,
  },
  back: {
    backgroundColor: '#e5e5e5',
    height: '100%',
    width: '100%',
    justifyContent: 'space-between',
  },
  fill: {
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
    paddingTop: '40%',
  },
  welcome: {
    fontSize: 20,
    fontWeight: 'bold',
    position: 'relative',
    alignSelf: "center",
    bottom: '10%',
  },
  buttonTextt: {
    color: '#20E9D0',
  },
  good: {
    color: 'red',
  }
});

export default Login;