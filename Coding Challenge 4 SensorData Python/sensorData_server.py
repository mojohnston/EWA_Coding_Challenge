import grpc
from concurrent import futures
import time
import sensorData_pb2_grpc as pb2_grpc
import sensorData_pb2 as pb2


class SensorDataService(pb2_grpc.SensorDataServicer):

    def __init__(self, *args, **kwargs):
        pass

    def GetServerResponse(self, request, context):

        # get the doubles from the incoming request
        resistance = request.resistance
        humidity = request.humidity
        tempC = request.tempC
        tempF = request.tempF
        result = f'I have just received sensor data "Resistance = {resistance} kiloOhms, Humidity = {humidity} %, Temperature = {tempC} degrees C, {tempF} degrees F" from you'
        result = {'responseMessage': result, 'received': True}
        print(f'{result}')
        return pb2.MessageResponse(**result)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    pb2_grpc.add_SensorDataServicer_to_server(SensorDataService(), server)
    server.add_insecure_port('[::]:50056')
    server.start()
    server.wait_for_termination()


if __name__ == '__main__':
    serve()