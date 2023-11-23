if [ $# -lt 0 ]; then # checks if number of arguments is less than 1
    echo "Usage: 'sh pipeine.sh"
    return 1
fi

if $(docker image ls | grep -q egcs-base-arm)
then
    echo "egcs-base-arm img exists, building egcs-arm"
    sh scripts/build_img.sh scripts/Dockerfile_arm egcs-arm

    if $(docker ps | grep -q egcs)
    then
        echo "egcs still active, stopping."
        sh scripts/stop.sh egcs
    else
        echo "egcs-arm already stopped."
    fi

    yes | docker container prune

    sh scripts/spinup.sh egcs-arm egcs
else
    echo "egcs-base-arm img does not exist, building base img"
    sh scripts/build_img.sh scripts/Dockerfile_arm_base egcs-base-arm
fi