from pyparticleio.ParticleCloud import ParticleCloud
import timeit

particle_cloud = ParticleCloud(access_token)

timeit.timeit('particle_cloud.downstairs.getTemperature()', number = 10, globals=globals())
timeit.timeit('particle_cloud.downstairs.temperature', number = 10, globals=globals())
