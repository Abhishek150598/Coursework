import axios from 'axios';

const getMessageHistory = (username) => {

    const config = {
        headers: {Authorisation: "Bearer " + sessionStorage.getItem("AuthToken")},
        params: { username }
    };

    return axios.get("http://localhost:8000/apis/getMessages/", config)
    .then(response => response.data.messages)
    .catch(err => []);
}

export default getMessageHistory;