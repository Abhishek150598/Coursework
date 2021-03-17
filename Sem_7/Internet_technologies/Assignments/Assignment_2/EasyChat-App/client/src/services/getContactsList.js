import axios from 'axios';

const getContactsList = () => {

    const config = {
        headers: {Authorisation: "Bearer " + sessionStorage.getItem("AuthToken")},
    };

    return axios.get("http://localhost:8000/apis/getContacts", config)
    .then(response => response.data.contacts)
    .catch(err => []);
  
}

export default getContactsList;