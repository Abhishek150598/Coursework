const mongoose = require("mongoose");
const Message = mongoose.model("Message");
const {updateContacts} = require("./updateContacts");

exports.postMessage = async ({to, from, body}) => {
    try {
        const newMessage = new Message({
            to,
            from,
            body,
        });
        await newMessage.save();
        console.log("New message posted");
        await updateContacts(to, from, body);
        console.log("Contacts updated");

    } catch(err) {
        console.log(err);
    }
    
};