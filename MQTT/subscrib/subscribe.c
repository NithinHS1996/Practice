#include <stdio.h>
#include <stdlib.h>

#include <mosquitto.h>

void on_connect(struct mosquitto *mosq, void *obj, int rc)
{
    printf("client ID: %d\n", *(int *)obj);
    if (rc)
    {
        printf("error with result code: %d\n", rc);
        exit(-1);
    }
    mosquitto_subscribe(mosq, NULL, "test/tl", 0);
}

void on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg)
{
    printf("New messge with topic %s: %s\n", msg->topic, (char *)msg->payload);
}

int main()
{
    int rc, id = 12;
    mosquitto_lib_init();
    struct mosquitto *mosq;
    mosq = mosquitto_new("subscirbe-test", true, &id);
    mosquitto_connect_callback_set(mosq, on_connect);
    mosquitto_message_callback_set(mosq, on_message);
    rc = mosquitto_connect(mosq, "localhost", 1883, 10);
    if (rc)
    {
        printf("Could not connect ot cient: %d\n", rc);
        return -1;
    }
    mosquitto_loop_start(mosq);
    printf("Press Enter to quit\n");
    getchar();
    mosquitto_loop_stop(mosq, true);
    mosquitto_disconnect(mosq);
    mosquitto_lib_cleanup();
    return 0;
}