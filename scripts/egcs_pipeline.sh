if [ $# -lt 0 ]; then # checks if number of arguments is less than 1
    echo "Usage: 'sh pipeine.sh"
    return 1
fi

if $(docker image ls | grep -q egcs-arm-baseimg)
then
    echo "egcs-arm-baseimg img exists, building egcs-arm-img"
    sh scripts/build_img.sh scripts/Dockerfile_arm egcs-arm-img

    if $(docker ps | grep -q egcs-arm-container)
    then
        echo "egcs-arm-container still active, stopping."
        sh scripts/stop.sh egcs-arm-container
    else
        echo "egcs-arm-container already stopped."
    fi

    yes | docker container prune

    sh scripts/spinup.sh egcs-arm-img egcs-arm-container
else
    echo "egcs-arm-baseimg img does not exist, building base img"
    sh scripts/build_img.sh scripts/Dockerfile_arm_base egcs-arm-baseimg
fi