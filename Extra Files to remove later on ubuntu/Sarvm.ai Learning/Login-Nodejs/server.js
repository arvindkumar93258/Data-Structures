const express = require('express')
const bcrypt = require('bcrypt');


const PORT = process.env.PORT || 3000;


const app = express();
app.use(express.json());


const users = [

]

app.get('/get-users', async (req, res) => {
    res.json(users);
})

app.post('/register', async (req, res) => {
    try {
        const hashedPassword = await bcrypt.hash(req.body.password, 10);
        const user = { username: req.body.username, password: hashedPassword };
        users.push(user);
        res.status(201).send("User registered!");

    }
    catch {
        res.status(500).send("Server error! sorry");
    }
})

app.post('/users/login', async (req, res) => {
    try {
        const user = await users.find(user => user.username === req.body.username);
        if (user == null) {
            res.status(400).send("User does not exist!");
        } else {
            if (await bcrypt.compare(req.body.password, user.password)) {
                res.status(200).send("Successfull!");
            } else {
                res.status(400).send("Password is wrong!");
            }
        }

    } catch(err) {
        console.log(err);
        res.status(500).send("Server error");
    }

})



app.listen(PORT, () => {
    console.log(`Server is running on https://localhost/${PORT}`)
})