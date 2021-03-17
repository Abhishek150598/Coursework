const mongoose = require("mongoose");
const Message = mongoose.model("Message");
const BroadcastMessage = mongoose.model("BroadcastMessage");
const User = mongoose.model("User");
exports.getMessages = async (req, res) => {
    try {
        const user1 = req.query.username;
        const user2 = req.payload.username;
        let messages;
        
        if(user1 == 'Broadcast Channel') {
            messages = await BroadcastMessage.find({}).sort({'createdAt': -1});
        }
        else {
            messages = await Message.find({
                $or: [{ to: user1, from: user2 }, { to: user2, from: user1 }],
            }).sort({'createdAt': -1});

            // When user2 asks for user1's messages it is assumed that he has read all messages
            await User.updateOne({
                "username": user2,
                "contacts.name": user1
            }, {
                $set: {"contacts.$.unread": 0},
            });
        }
        
        res.json({
            messages,
        })
    
    } catch(err) {
        console.log(err);
        res.status(400).json({
            message: err,
        });
    }
    
};