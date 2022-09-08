const express = require('express');
const dotenv = require('dotenv');

const PORT = process.env.PORT || 3000;
const app = express();

app.get('/', async(req, res)=>{
    console.log("Hello world");
})

app.post('/login', (req, res)=>{

})


app.listen(PORT, ()=>{
    console.log(`Server is running on http://localhost:${PORT}/`);
})