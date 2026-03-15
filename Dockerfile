FROM python:3.12

COPY tls/server.py .
# COPY server.crt .
# COPY rootCA.pem .
# COPY server.key .

COPY pki/generate_ca.sh .

RUN chmod +x generate_ca.sh && ./generate_ca.sh

EXPOSE 8443

CMD ["python","server.py"]