const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'qqqq',
  database: 'pankki'
});
module.exports = connection;