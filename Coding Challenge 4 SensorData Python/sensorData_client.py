import grpc
import sensorData_pb2_grpc as pb2_grpc
import sensorData_pb2 as pb2


class SensorDataClient(object):
    """
    Client for gRPC functionality
    """

    def __init__(self):
        self.host = 'localhost'
        self.server_port = 50056

        # instantiate a channel
        self.channel = grpc.insecure_channel(
            '{}:{}'.format(self.host, self.server_port))

        # bind the client and the server
        self.stub = pb2_grpc.SensorDataStub(self.channel)

    def get_url(self, resistance, humidity, tempC, tempF):
        """
        Client function to call the rpc for GetServerResponse
        """
        message = pb2.SensorMessage(resistance=resistance, humidity=humidity, tempC=tempC, tempF=tempF)

        print(f'{message}')

        return self.stub.GetServerResponse(message)


if __name__ == '__main__':
    client = SensorDataClient()
    result = client.get_url(resistance=4.39, humidity=35.2, tempC=22.7, tempF=72.86)
    print(f'{result}')