// API Server with node.js
// without express
const fs = require('fs');
const http = require('http');
const querystring = require('querystring');

const port = process.env.PORT || 1337

function defaultResponse (req, res) {
  res.writeHead(200, {'Content-Type': 'text/plain'});
  res.end('200 OK');
}

function defaultJson (req, res) {
  res.setHeader('Content-Type', 'application/json');
  res.end(JSON.stringify({ text: 'basic object', numbers: [1, 2, 3] }));
}

function respondQueryParam(req, res) {
  // Structure: /data?param=value
  const { param = '' } = querystring.parse(req.url.split('?').slice(1).join(''));
  res.setHeader('Content-Type', 'application/json');
  res.end(JSON.stringify({
    queryParam: {
      value: param
    }
  }));
}

function getFile(req, res) {
  const filename = `${__dirname}${req.url.split('/files')[1]}`
  fs.createReadStream(filename)
    .on('error', () => respondNotFound(req, res))
    .pipe(res)
}

function respondNotFound (req, res) {
  res.writeHead(404, { 'Content-Type': 'text/plain' })
  res.end('404 Not Found')
}

const server = http.createServer(
  (req, res) => {
    if (req.url === '/') return defaultResponse(req, res)
    if (req.url === '/json') return defaultJson(req, res)
    if (req.url.match(/^\/data/)) return respondQueryParam(req, res)    
    if (req.url.match(/^\/files/)) return getFile(req, res)
    
    respondNotFound(req, res)
  }
);

server.listen(port);
console.log(`Server started on port ${port}`);
