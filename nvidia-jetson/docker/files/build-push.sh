#!/bin/bash

# Set the script to exit when any command fails
set -e

# Build the image
docker build -f jetson-arm-Dockerfile.base . -t us-central1-docker.pkg.dev/<repo>/base

# Push the image
docker push us-central1-docker.pkg.dev/<repo>/base
