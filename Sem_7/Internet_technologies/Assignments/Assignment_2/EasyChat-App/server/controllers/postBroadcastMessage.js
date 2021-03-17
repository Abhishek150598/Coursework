const mongoose = require("mongoose");
const BroadcastMessage = mongoose.model("BroadcastMessage");

exports.postBroadcastMessage = async ({from, body}) => {
    try {
        const newMessage = new BroadcastMessage({
            from,
            body,
        });
        await newMessage.save();
        console.log("New message posted");
    } catch(err) {
        console.log(err);
    }
    
};