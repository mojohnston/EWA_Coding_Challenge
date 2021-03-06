# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: sensorData.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='sensorData.proto',
  package='sensorData',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x10sensorData.proto\x12\nsensorData\"S\n\rSensorMessage\x12\x12\n\nresistance\x18\x01 \x01(\x01\x12\x10\n\x08humidity\x18\x02 \x01(\x01\x12\r\n\x05tempC\x18\x03 \x01(\x01\x12\r\n\x05tempF\x18\x04 \x01(\x01\"<\n\x0fMessageResponse\x12\x17\n\x0fresponseMessage\x18\x01 \x01(\t\x12\x10\n\x08received\x18\x02 \x01(\x08\x32[\n\nSensorData\x12M\n\x11GetServerResponse\x12\x19.sensorData.SensorMessage\x1a\x1b.sensorData.MessageResponse\"\x00\x62\x06proto3'
)




_SENSORMESSAGE = _descriptor.Descriptor(
  name='SensorMessage',
  full_name='sensorData.SensorMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='resistance', full_name='sensorData.SensorMessage.resistance', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='humidity', full_name='sensorData.SensorMessage.humidity', index=1,
      number=2, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='tempC', full_name='sensorData.SensorMessage.tempC', index=2,
      number=3, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='tempF', full_name='sensorData.SensorMessage.tempF', index=3,
      number=4, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=32,
  serialized_end=115,
)


_MESSAGERESPONSE = _descriptor.Descriptor(
  name='MessageResponse',
  full_name='sensorData.MessageResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='responseMessage', full_name='sensorData.MessageResponse.responseMessage', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='received', full_name='sensorData.MessageResponse.received', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=117,
  serialized_end=177,
)

DESCRIPTOR.message_types_by_name['SensorMessage'] = _SENSORMESSAGE
DESCRIPTOR.message_types_by_name['MessageResponse'] = _MESSAGERESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

SensorMessage = _reflection.GeneratedProtocolMessageType('SensorMessage', (_message.Message,), {
  'DESCRIPTOR' : _SENSORMESSAGE,
  '__module__' : 'sensorData_pb2'
  # @@protoc_insertion_point(class_scope:sensorData.SensorMessage)
  })
_sym_db.RegisterMessage(SensorMessage)

MessageResponse = _reflection.GeneratedProtocolMessageType('MessageResponse', (_message.Message,), {
  'DESCRIPTOR' : _MESSAGERESPONSE,
  '__module__' : 'sensorData_pb2'
  # @@protoc_insertion_point(class_scope:sensorData.MessageResponse)
  })
_sym_db.RegisterMessage(MessageResponse)



_SENSORDATA = _descriptor.ServiceDescriptor(
  name='SensorData',
  full_name='sensorData.SensorData',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_start=179,
  serialized_end=270,
  methods=[
  _descriptor.MethodDescriptor(
    name='GetServerResponse',
    full_name='sensorData.SensorData.GetServerResponse',
    index=0,
    containing_service=None,
    input_type=_SENSORMESSAGE,
    output_type=_MESSAGERESPONSE,
    serialized_options=None,
    create_key=_descriptor._internal_create_key,
  ),
])
_sym_db.RegisterServiceDescriptor(_SENSORDATA)

DESCRIPTOR.services_by_name['SensorData'] = _SENSORDATA

# @@protoc_insertion_point(module_scope)
