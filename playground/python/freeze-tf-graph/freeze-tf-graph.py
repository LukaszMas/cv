#!/usr/bin/env python3

"""
Convert tf model to opencv
"""

# --- Standard Library --------------------------------------------------------

import os
import argparse

# --- External Library --------------------------------------------------------

import cv2
import numpy as np
import tensorflow as tf
from tensorflow.python.framework.convert_to_constants import convert_variables_to_constants_v2

# --- Global parameters -------------------------------------------------------

# Directory for the frozen .pb model
PB_MODEL_PATH = "models"
# Name of the frozen .pb model
PB_MODEL_NAME = "frozen_model.pb"

# --- Main --------------------------------------------------------------------

def main(args: argparse.Namespace) -> None:
    """ Main converts saved tf model into OpenCV usable """

    # Create directory for the further converted model
    os.makedirs(pb_model_path, exist_ok=True)

    # NOTE there are different ways to load saved tf models
    # TODO Handle based on model extension or what is present in the dir?
    imported_model = tf.keras.models.load_model(model_path)
    frozen_model = get_tf_model_proto(imported_model)

    # NOTE example usage with opencv dnn module:
    #frozen_model = PB_MODEL_PATH + "/" PB_MODEL_NAME"
    #net = cv2.dnn.readNetFromTensorflow(frozen_model)

# --- Helpers -----------------------------------------------------------------

def get_tf_model_proto(tf_model):
    # Conver Keras model to ConcreteFunction
    tf_model_graph = tf.function(lambda x: tf_model(x))
    tf_model_graph = tf_model_graph.get_concrete_function(
        tf.TensorSpec(tf_model.inputs[0].shape, tf_model.inputs[0].dtype))

    # get frozen ConcreteFunction
    frozen_tf_func = convert_variables_to_constants_v2(tf_model_graph)
    # get frozen graph
    frozen_tf_func.graph.as_graph_def()

    # save full tf model
    tf.io.write_graph(graph_or_graph_def=frozen_tf_func.graph,
                      logdir=PB_MODEL_PATH,
                      name=PB_MODEL_NAME,
                      as_text=False)

    return os.path.join(pb_model_path, pb_model_name)

# --- init --------------------------------------------------------------------

if __name__ == "__main__":
    PARSER = argparse.ArgumentParser(description="Test model inference")
    PARSER.add_argument("-m", "--model-path",  type=str, metavar="Model path", required=True,
                        help="Path to the saved tf model")
    parser.add_argument("-c", "--config-path", type=str, metavar="Model config", required=True,
                        help="Path to the model's .pbtxt")
    main(PARSER.parse_args())
