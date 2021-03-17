const jwt = require("jwt-then");

exports.authorisation = async (req, res, next) => {
  try {
    if (!req.headers.authorisation) 
        throw "Forbidden!!";
    const token = req.headers.authorisation.split(" ")[1];
    const payload = await jwt.verify(token, process.env.SECRET);
    req.payload = payload;
    next();
  } catch (err) {
    console.log(err);
    res.status(401).json({
      message: err,
    });
  }
};