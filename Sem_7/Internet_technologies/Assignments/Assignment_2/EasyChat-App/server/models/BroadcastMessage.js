const mongoose = require("mongoose");

const broadcastMessageSchema = new mongoose.Schema(
  {
    from: {
        type: String,
        required: true,
    },
    body: {
        type: String,
        required: true,
    },
  }, {
    timestamps: true
  }
);

module.exports = mongoose.model("BroadcastMessage", broadcastMessageSchema);