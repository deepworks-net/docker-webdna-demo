#!/bin/sh

DOCKER_UTILS_TAG_EM=${DOCKER_UTILS_TAG_EM:-YES}
DOCKER_UTILS_ENV=${DOCKER_UTILS_ENV:-".env"}
DOCKER_UTILS_FUNCTIONS=${DOCKER_UTILS_FUNCTIONS:-"scripts/utils/funcs.sh"}

# Load functions
. "$DOCKER_UTILS_FUNCTIONS"

# Load variables
GET_ENV_VARS "$DOCKER_UTILS_ENV"

echo "Building via Compose $IMAGE_NAME - $IMAGE_VERSION"
BTP_IMAGE --image-name "$IMAGE_NAME" \
            --image-version "$IMAGE_VERSION" \
            --service "$SERVICE_NAME" \
            --compose

