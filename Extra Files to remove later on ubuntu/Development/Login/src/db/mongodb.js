const mongoose = require('mongoose');


/*, {
    useNewUrlParser : true,
    newUnifiedTopology : true,
    useCreateIndex : true
*/
mongoose.connect("mongodb://localhost:27017/logonDB")
.then(()=>{
    console.log("Connecting Database Successfull ! ");
})
.catch(()=>{
    console.log("Failed to connect Database");
})