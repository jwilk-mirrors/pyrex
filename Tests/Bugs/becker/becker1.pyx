cdef class _Box:
    cdef readonly int penalty, flagged, is_glue, is_penalty, is_box
    cdef char* character
    cdef double width, stretch, shrink

cdef class Box(_Box):
    """Class representing a glyph or character.  Boxes have a fixed
    width that doesn't change.
    """
    def __init__(self, double width, char* character):
        self.character = character
        self.width = width
        self.stretch = self.shrink = self.penalty = self.flagged = self.is_glue = self.is_penalty = 0
        self.is_box = 1

cdef class Glue(_Box):
    """Class representing a bit of glue.  Glue has a preferred width,
    but it can stretch up to an additional distance, and can shrink
    by a certain amount.  Line breaks can be placed at any point where
    glue immediately follows a box.
    """
    def __init__(self, double width, double stretch, double shrink):
        self.width = width
        self.stretch = stretch
        self.shrink = shrink
        self.is_glue = 1
        self.is_box = self.is_penalty = 0

    cdef compute_width(self, double r):
        # Return how long this glue should be, for the given adjustment
        # ratio r.
        if r < 0:   return self.width + r*self.shrink
        else:       return self.width + r*self.stretch
