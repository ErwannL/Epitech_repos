import { API_KEY } from "./config";
import { Alert } from "react-native";

async function API(username, password) {
    // Define the request data
    const url = 'https://masurao.fr/api/employees/login';
    const headers = {
      'accept': 'application/json',
      'X-Group-Authorization': API_KEY,
      'Content-Type': 'application/json',
    };

    const body = JSON.stringify({
      email: username,
      password: password,
    });

    const response = await fetch(url, {
      method: 'POST',
      headers: headers,
      body: body,
    })
    if (response.ok) {
      return response.json();
    } else if (response.status === 503) {
      Alert.alert("Error", "Server timed out");
      throw new Error("Server timed out");
    } else if (response.status === 401) {
      Alert.alert("Error", "Login or Password invalid");
      throw new Error("Login or Password invalid");
    } else {
      Alert.alert("Error", "Error unexpected");
      throw new Error("Error unexpected");
    }
}
  
  export default API;