import axios from 'axios';

const getUsersList = () => {
    
    return axios.get("http://localhost:8000/apis/getUsers", {
        headers: {
            Authorisation: "Bearer " + sessionStorage.getItem("AuthToken"),
        }
    })
    .then(response => response.data.users)
    .catch(err => []);   
}

export default getUsersList;