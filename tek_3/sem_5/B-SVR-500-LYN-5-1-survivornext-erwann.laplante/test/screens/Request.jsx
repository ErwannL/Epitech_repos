import { API_KEY } from "./config";

async function Request(url, accept, token) {
    // Define the request date
    const headers = {
      'accept': accept,
      'X-Group-Authorization': API_KEY,
      'Authorization': `Bearer ${token}`,   
    };

    const response = await fetch(url, {
      method: 'GET',
      headers: headers,
    })
    if (response.ok) {
      return response.json();
    } else if (response.status === 503) {
      throw new Error("Server timed out");
    } else if (response.status === 401) {
      throw new Error("Not authorized");
    } else {
      throw new Error("Error unexpected");
    }
}
  
  export default Request;