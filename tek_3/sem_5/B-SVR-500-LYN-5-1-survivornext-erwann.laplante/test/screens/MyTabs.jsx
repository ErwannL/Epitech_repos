import React from "react";
import { View, Text, StyleSheet} from "react-native";
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { NavigationContainer } from "@react-navigation/native";
import MaterialCommunityIcons from 'react-native-vector-icons/MaterialCommunityIcons';
import Trombi from "./Trombi";
import Widgets from "./Widgets";
import Profile from "./Profile";



const MyTabs = ({ navigation }) => {
    const Tab = createBottomTabNavigator();

    return (
        <Tab.Navigator initialRouteName="Feed" screenOptions={{tabBarActiveTintColor: '#ec57ff',}}>
            <Tab.Screen 
            name="Home" component={Trombi} 
                options={{tabBarLabel: 'Home',
                headerShown: false,
                tabBarIcon: ({ color, size }) => (
                    <MaterialCommunityIcons name="home" color={color} size={size} />
                    ),
                }}
            />
            <Tab.Screen
                name="Widgets" component={Widgets}
                options={{
                    tabBarLabel: 'Widgets',
                    headerShown: false,
                    tabBarIcon: ({ color, size }) => (
                        <MaterialCommunityIcons name="cellphone" color={color} size={size} />
                    ),
                }}
            />
            <Tab.Screen
                name="Profile" component={Profile}
                options={{
                    tabBarLabel: 'Profile',
                    headerShown: false,
                    tabBarIcon: ({ color, size }) => (
                        <MaterialCommunityIcons name="account" color={color} size={size} />
                    ),
                }}
            />

        </Tab.Navigator>
    );
};

export default MyTabs;
