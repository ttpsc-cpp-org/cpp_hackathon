
# Use an official Python runtime as a parent image
FROM ubuntu:22.04

# Set the working directory in the container to /app
WORKDIR /app
ADD . /app
# Add metadata to the image to describe that the container is used for Github Codespaces
LABEL name="cpp_hackathon Codespace" \
      vendor="cpp_hackathon" \
      version="1.0" \
      release="1" \
      summary="Container for cpp_hackathon development" \
      description="This is a development environment for cpp_hackathon project"

# Install any needed packages specified in requirements.txt
# Copy only the necessary files
COPY requirements.txt ./
#RUN pip install --no-cache-dir -r requirements.txt

# Copy the rest of your application code
COPY . .

# Install CMake and Conan
RUN apt-get update && apt-get install -y gcc cmake build-essential --fix-missing

# Clean up
RUN apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*

RUN ./bootstrap.sh