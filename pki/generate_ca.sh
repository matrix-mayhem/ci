#!/bin/bash

# Root CA
openssl genrsa -out rootCA.key 2048

openssl req -x509 -new -nodes -key rootCA.key -sha256 -days 365 -out rootCA.pem -subj "/CN=DemoRootCA"

# Server certificate
openssl genrsa -out server.key 2048

openssl req -new -key server.key -out server.csr -subj "/CN=secure-server"

openssl x509 -req -in server.csr -CA rootCA.pem -CAkey rootCA.key -CAcreateserial -out server.crt -days 365 -sha256

# Client certificate
openssl genrsa -out client.key 2048

openssl req -new -key client.key -out client.csr -subj "/CN=secure-client"

openssl x509 -req -in client.csr -CA rootCA.pem -CAkey rootCA.key -out client.crt -days 365