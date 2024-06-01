const http = require('http');
const {type} = require('os');

const server = http.createServer();

server.listen(4000, 'localhost');

server.on('listening', () => {
  console.log('Server OK');
});

server.on('request', (request, response) => {
  const {method, url} = request;
  console.log('Server URL: %s %s', method, url);
  response.setHeader('Content-Type', 'text/html; charset=utf-8');
  response.write('<h1>Rendering response</h1>');
  response.write('<p>OS: '+type()+'</p>');
  response.end();
});
