"""
This problem was asked by Stripe.

Write a function to flatten a nested dictionary. Namespace the keys with a period.

For example, given the following dictionary:

{
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}
it should become:

{
    "key": 3,
    "foo.a": 5,
    "foo.bar.baz": 8
}
You can assume keys do not contain dots in them, i.e. no clobbering will occur.
"""

def flatten_helper(d, flat_d, path):
    if not isinstance(d, dict):
        flat_d[path] = d
        return

    for key in d:
        if path:
            new_path = path + "." + key
        else:
            new_path = key
        flatten_helper(d[key], flat_d, new_path)

def flatten(d):
    flat_d = dict()
    flatten_helper(d, flat_d, "")
    return flat_d

d = {
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8,
            "bez": 10
        }
    }
}

print(flatten(d))