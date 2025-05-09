import React, { useState } from 'react';
import { Text, TextInput, View, Image, Button, ScrollView, FlatList, StyleSheet, SectionList, TouchableOpacity} from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import Trombi from './screens/Trombi';
import MyTabs from './screens/MyTabs';
import Login from './screens/Login';
import { DetailInfos } from './screens/Context';
import OtherProfile from './screens/OtherProfile';

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

const Stack = createNativeStackNavigator();

function MyApp() {
  return (
    <DetailInfos>
     <NavigationContainer>
      <Stack.Navigator initialRouteName="Login">
          <Stack.Screen name="Login" component={Login} options={{headerShown: false}} />
          <Stack.Screen name="MyTabs" component={MyTabs} options={{headerShown: false}} />
          <Stack.Screen name="OtherProfile" component={OtherProfile} options={{headerShown: false}} />
      </Stack.Navigator>
    </NavigationContainer>  
    </DetailInfos>
  );
};

// const MyApp = () => {
//   const Tab = createNativeStackNavigator();
//   
//   return (
//     <MyTabs />  
//   );
    // <ScrollView style={styles.back}>
    //   <View style={styles.doctorsContainer}>
    //     { FakeEmployee.map((employee, index)=>{
    //         return (
    //           <TouchableOpacity key={employee.id} style={styles.doctorCard}>
    //             <Image
    //               source={{uri: `${employee.img}`}}
    //               style={styles.employeeImg}
    //             />
    //             <View style={styles.employeeInfo}>
    //               <Text style={styles.employeeName}>{employee.fullname}</Text>
    //               <View style={styles.employeeSpeContainer}>
    //                 <Text style={styles.employeeSpe}>{employee.speciality}</Text>
    //               </View>
    //             </View>
    //           </TouchableOpacity>
    //         );
    //     })}
    //   </View>
    // </ScrollView>
// };

export default MyApp;