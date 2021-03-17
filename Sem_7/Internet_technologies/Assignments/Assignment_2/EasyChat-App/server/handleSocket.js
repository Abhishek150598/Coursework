const mongoose = require("mongoose");
const jwt = require("jwt-then");
const {postMessage} = require("./controllers/postMessage");
const {postBroadcastMessage} = require("./controllers/postBroadcastMessage");

exports.handleSocket = (server) => {
    const io = require("socket.io")(server, {
        cors: {
          origin: "http://localhost:3000",
          methods: ["GET", "POST"],
          allowedHeaders: ["my-custom-header"],
          credentials: true
        }
    });
    var userSocketMap = {};
    
    io.use(async (socket, next) => {
        try {
          const token = socket.handshake.query.token;
          const payload = await jwt.verify(token, process.env.SECRET);
          socket.username = payload.username;
          userSocketMap[socket.username] = socket.id;
          next();
        } catch (err) {
            console.log(err);
        }
    });
      
    io.on("connection", (socket) => {
        console.log("Connected: " + socket.username);

        socket.on("disconnect", () => {
            console.log("Disconnected: " + socket.username);
        });

        socket.on("message", async ({ to, message }) => {
            try {
                if(to === 'Broadcast Channel') {
                    await postBroadcastMessage({
                        from: socket.username,
                        body: message,
                    })
                    await io.sockets.emit("message", {
                        message: message,
                        from: socket.username,
                    });
                }
                else {
                    await postMessage({
                        to: to,
                        from: socket.username,
                        body: message,
                    });
                    await io.to(userSocketMap[to]).emit("message", {
                        message: message,
                        from: socket.username,
                    });
                    
                }
                io.to(userSocketMap[socket.username]).emit("ack");
                
            } catch(err) {
                console.log(err);
            }
        });

    })
    
};