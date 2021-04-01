const express = require('express');
const router = express.Router();
const customer = require('../models/customer_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    customer.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
          //palautetaan json objekti eli ainoa alkio -> [0]
        response.json(dbResult[0]);
      }
    });
  } else {
    customer.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});


router.post('/', 
function(request, response) {
  customer.add(request.body, function(err, dbResult) {
    if (err) {
      console.log(dbResult);
      response.json("Virhe lisätessä käyttäjää");
    } else {
      response.json("Uusi käyttäjä lisätty");
    }
  });
});


router.delete('/:id', 
function(request, response) {
  customer.delete(request.params.id, function(err, dbResult) {
    if (err) {
      console.log(dbResult);
      response.json("Käyttäjää ei löydy");
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  customer.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
        console.log(dbResult);
        response.json(err);
    }
    //  else {
    //     response.json(err);
    //      console.log(dbResult);
    // }
    if(dbResult.affectedRows==1){
        response.json("Käyttäjää päivitetty");
    }
    else{
        response.json("Käyttäjää ei löydy");
    }
  });
});

module.exports = router;