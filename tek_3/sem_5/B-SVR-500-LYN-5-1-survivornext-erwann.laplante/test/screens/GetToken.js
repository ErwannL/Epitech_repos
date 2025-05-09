import * as SecureStore from 'expo-secure-store'

const getToken = async (key) => {
    try {
      const token = await SecureStore.getItemAsync(key);
      if (token) {
        return token;
      } else {
        console.log('No token found in SecureStore');
        return null;
      }
    } catch (error) {
      console.error('Error retrieving token:', error);
      return null;
    }

};

  export default getToken;