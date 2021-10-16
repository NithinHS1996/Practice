#include <stdio.h>
#include <mosquitto.h>

int main()
{
    int rc;
    struct mosquitto *mosq;
    mosquitto_lib_init();
    mosq = mosquitto_new("publisher-test", true, NULL);
    rc = mosquitto_connect(mosq, "localhost", 1883, 60);
    if (rc != 0)
    {
        printf("client could not connect to broker! Error code: %d\n", rc);
        mosquitto_destroy(mosq);
        return -1;
    }
    printf("we are now connected to broker\n");
    mosquitto_publish(mosq, NULL, "test/tl", 6, "Hello", 0, false);
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
    return 0;
}