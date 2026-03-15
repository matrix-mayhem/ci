import http.server
import ssl

httpd = http.server.HTTPServer(("0.0.0.0", 8443), http.server.SimpleHTTPRequestHandler)

context = ssl.create_default_context(ssl.Purpose.CLIENT_AUTH)
context.load_cert_chain(certfile="server.crt", keyfile="server.key")
context.load_verify_locations("rootCA.pem")
context.verify_mode = ssl.CERT_REQUIRED

httpd.socket = context.wrap_socket(httpd.socket, server_side=True)

print("mTLS server started on port 8443")

httpd.serve_forever()