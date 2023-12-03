const express = require('express');
const router = express.Router();

//Game Model
const Game = require('../../models/Game');

// @route   GET api/games
// @desc    Get All games
// @access  Public
// '/' = '/api/games'
router.get('/', (req,res) =>{
    Game.find()
        .sort({ date: -1 })
        .then(games => res.json(games))
});

// @route Get api/games/id
// @desc Get specific game
// @access Public
router.get('/:id',(req,res) =>{
    Game.findById(req.params.id)
    .then(games => res.json(games))
    .catch(err => res.status(404).json({success: false}));
});


// @route Get api/games/id/teamA/
// @desc Get specific team in game
// @access Public
router.get('/:id/teamA/',(req,res) =>{
    Game.findById(req.params.id)
    .then(games => res.json(games.teamA))
    .catch(err => res.status(404).json({success: false}));
});

// @route Get api/games/id/teamA/int
// @desc Get specific player of teamA
// @access Public

router.get('/:id/teamA/:i',(req,res) =>{
    Game.findById(req.params.id)
    .then(games => res.json(games.teamA.players[req.params.i]))
    .catch(err => res.status(404).json({success: false}));
});

// @route Get api/games/id/teamB/
// @desc Get specific game
// @access Public
router.get('/:id/teamB/',(req,res) =>{
    Game.findById(req.params.id)
    .then(games => res.json(games.teamB))
    .catch(err => res.status(404).json({success: false}));
});

// @route Get api/games/id/teamB/int
// @desc Get specific player of teamB
// @access Public
router.get('/:id/teamB/:i',(req,res) =>{
    Game.findById(req.params.id)
    .then(games => res.json(games.teamB.players[req.params.i]))
    .catch(err => res.status(404).json({success: false}));
});

// @route   POST api/games
// @desc    Create an Game
// @access  Public
router.post('/', (req,res) =>{
    const newGame = new Game({
        teamA: req.body.teamA,
        teamB: req.body.teamB,
        date: req.body.date
    });

    newGame.save().then(game => res.json(game));
    
});

// @route   DELETE api/games/:id
// @desc    Delete a Game
// @access  Public
router.delete('/:id', (req,res) =>{
    Game.findById(req.params.id)
        .then(game => game.remove().then(() => res.json({success: true})))
        .catch(err => res.status(404).json({success: false}));
});




module.exports =  router;