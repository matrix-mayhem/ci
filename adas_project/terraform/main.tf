provider "aws" {
    region = "ap-south-1"
}

resource "aws_instance" "jenkins"{
    ami = "ami-0f559c3642608c138"
    instance_type = "t3.micro"
    key_name = "jenkins-key"
}