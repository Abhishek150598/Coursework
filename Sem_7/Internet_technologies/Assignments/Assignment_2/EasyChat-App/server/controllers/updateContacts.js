const mongoose = require("mongoose");
const User = require("../models/User");

exports.updateContacts = async (to, from, message) => {
    try {
        console.log("update: received:" + to + " " + from + " " + message);
        const user = await User.findOne({ 
            username: to, 
            contacts: {
                $elemMatch: {name: from}
            }
        });

        // If contact already exists update the lastMessage
        if(user) {
            // Updating receiver's contact
            await User.updateOne({
                "username": to,
                "contacts.name": from
            }, {
                $set: {"contacts.$.lastMessage": message},
                $inc: {"contacts.$.unread": 1}
            });

            // Updating sender's contact
            await User.updateOne({
                "username": from,
                "contacts.name": to
            }, {
                $set: {"contacts.$.lastMessage": message},
            });
        }
        // Else, add new contact to contacts array
        else {
            // Updating receiver's contact
            await User.updateOne({
                "username": to,
            }, {
                $push: { contacts: { 
                        name: from, 
                        lastMessage: message,
                        unread: 1
                }}
            });

            // Updating sender's contact
            await User.updateOne({
                "username": from,
            }, {
                $push: { contacts: { 
                        name: to, 
                        lastMessage: message,
                        unread: 0
                }}
            });
        }

    } catch(err) {
        console.log(err);
    }
    
};