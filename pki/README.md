openssl genrsa -out private.pem 2048
openssl req -new -x509 -key private.pem -out cert.pem

In real pipelines you should not store private.pem in GitHub.

Instead:

store in Jenkins credentials

or Secrets Manager

2. Monitorings
Inside EC2
sudo yum install amazon-cloudwatch-agent


3. ec2 packages installation required
sudo yum install java-17-amazon-corretto -y
sudo yum install git -y

Service,Goal,Command
S3,List all buckets,aws s3 ls
S3,List files in a bucket,aws s3 ls s3://my-bucket-name
EC2,List all instances,aws ec2 describe-instances
VPC,List all VPCs,aws ec2 describe-vpcs
Lambda,List all functions,aws lambda list-functions
IAM,List all users,aws iam list-users
RDS,List DB instances,aws rds describe-db-instances
DynamoDB,List table names,aws dynamodb list-tables

3. GitHub Actions equivalent is multiple jobs:
jobs:

  build1:
    runs-on: ubuntu-latest
    steps:
      - run: echo build1

  build2:
    runs-on: ubuntu-latest
    steps:
      - run: echo build2

4. Give your user permission to run docker without 'sudo'
sudo usermod -aG docker $USER