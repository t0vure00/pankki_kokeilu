const db = require('../database');

const customer = {
  getById: function(id, callback) {
    return db.query('select * from customer where idcustomer=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from customer', callback);
  },
  add: function(customer, callback) {
    return db.query(
      'insert into customer (fname,lname,phonenumber,email) values(?,?,?,?)',
      [customer.fname, customer.lname, customer.phonenumber, customer.email],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from customer where idcustomer=?', [id], callback);
  },
  update: function(id, customer, callback) {
    return db.query(
      'update customer set fname=?, lname=?, phonenumber=?, email=? where idcustomer=?',
      [customer.fname, customer.lname, customer.phonenumber, customer.email, id],
      callback
    );
  }
};
module.exports = customer;