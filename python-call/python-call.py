from pyparticleio.ParticleCloud import ParticleCloud
import timeit

access_token = "de0ed9a2be479d4c5cfd89abbf04bfc591a92c7b"
particle_cloud = ParticleCloud(access_token)

timeit.timeit('particle_cloud.downstairs.getTemperature()', number = 10, globals=globals())
timeit.timeit('particle_cloud.downstairs.temperature', number = 10, globals=globals())