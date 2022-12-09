xhost + 127.0.0.1

docker run --rm -it --name "hyperlink-container" -e "DISPLAY=host.docker.internal:0" "hyperlink-image"
