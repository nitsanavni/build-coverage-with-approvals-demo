s/[123]a /0, /g
s/[123]b /1, /g
s/[123]c /2, /g
s/[123]d /3, /g
s/[123]e /4, /g
s/[123]f /5, /g
s/[123]g /6, /g
s/[123]h /7, /g
s/[123]i /8, /g
s/[123]j /9, /g

# surround each line with `{ },`
s/^ /  {/g
s/, $/},/g
