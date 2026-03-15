FROM python:3.12

COPY tls/server.py .
COPY server.crt .
COPY rootCA.pem .
COPY server.key .

EXPOSE 8443

CMD ["python","server.py"]