const express = require('express');
const router = express.Router();


// @route   GET files/
/*
router.get('/:id', (req,res) =>{


    var options = {
        headers:{
            'name': req.params.id
        }
    }

    res.sendFile(path.join(__dirname+'/game.html'),options);
});
*/



router.get('/:id/:file', (req,res) => {
    

    var options = {
        headers:{
            'name': req.params.id
        }
    }
    path = req.params.file
    console.log(path)

    router.use('./routes/static', express.static('./routes/static'));

    res.sendFile(path,{root:'routes/static'});
})


/*não é nada boa ideia fazer isto consegue ver outros ficheiros dentro
da mesma pasta
router.get('/:id', (req,res) =>{
    res.sendFile(path.join(__dirname+'/'+req.params.id));
});*/


module.exports =  router;