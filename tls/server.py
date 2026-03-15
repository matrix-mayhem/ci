import http.server
import ssl

class Handler(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.end_headers()
        self.wfile.write(b"Secure TLS/mTLS server running")

server = http.server.HTTPServer(("0.0.0.0", 8443), Handler)

server.socket = ssl.wrap_socket(
    server.socket,
    certfile="server.crt",
    keyfile="server.key",
    ca_certs="rootCA.pem",
    cert_reqs=ssl.CERT_REQUIRED
)

print("Secure mTLS server started on port 8443")

server.serve_forever()