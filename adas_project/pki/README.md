openssl genrsa -out private.pem 2048
openssl req -new -x509 -key private.pem -out cert.pem

In real pipelines you should not store private.pem in GitHub.

Instead:

store in Jenkins credentials

or Secrets Manager

2. Monitorings
Inside EC2
sudo yum install amazon-cloudwatch-agent
