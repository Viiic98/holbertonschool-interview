#!/usr/bin/node
const request = require('request');

const URL = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request(URL, function (error, response, body) {
  if (error) {
    console.error(error);
  }
  // Parse string body response to an object
  if (response.statusCode === 200) {
    const obj = JSON.parse(body);
    const characters = obj.characters;
    charsInFilm(characters, 0);
  }
});

function charsInFilm (characters, index) {
  if (index < characters.length) {
    request(characters[index], function (error, response, body) {
      if (error) {
        console.error(error);
      }
      // Parse string body response to an object
      if (response.statusCode === 200) {
        const char = JSON.parse(body);
        console.log(char.name);
        charsInFilm(characters, index + 1);
      }
    });
  }
}
