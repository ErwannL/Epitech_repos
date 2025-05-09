import * as SecureStore from 'expo-secure-store'

const storeToken = async (token, key) => {
    try {
      await SecureStore.setItemAsync(key, token);
    } catch (error) {
      console.error('Error storing token:', error);
    }
};
  
  export default storeToken;
